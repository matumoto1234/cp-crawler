package infra

import (
	"log"
	"net/http"

	"golang.org/x/time/rate"
)

// rateLimitTransport : リクエストの間隔を制限するTransport
type rateLimitTransport struct {
	Transport   http.RoundTripper
	rateLimiter *rate.Limiter
}

func (rlt *rateLimitTransport) transport() http.RoundTripper {
	if rlt.Transport == nil {
		return http.DefaultTransport
	}
	return rlt.Transport
}

func (rlt *rateLimitTransport) RoundTrip(req *http.Request) (*http.Response, error) {
	res, err := rlt.transport().RoundTrip(req)

	if err := rlt.rateLimiter.Wait(req.Context()); err != nil {
		return nil, err
	}

	return res, err
}

func (rlt *rateLimitTransport) CancelRequest(req *http.Request) {
	type cancelableTransport interface {
		CancelRequest(*http.Request)
	}
	if cr, ok := rlt.transport().(cancelableTransport); ok {
		cr.CancelRequest(req)
	}
}

func NewRateLimitTransport(transport http.RoundTripper, rateLimiter *rate.Limiter) *rateLimitTransport {
	return &rateLimitTransport{
		Transport:   transport,
		rateLimiter: rateLimiter,
	}
}

// loggingTransport : リクエストとレスポンスのログを出力するTransport
type loggingTransport struct {
	Transport http.RoundTripper
	logger    *log.Logger
}

func (lt *loggingTransport) transport() http.RoundTripper {
	if lt.Transport == nil {
		return http.DefaultTransport
	}
	return lt.Transport
}

func (lt *loggingTransport) RoundTrip(req *http.Request) (*http.Response, error) {
	res, err := lt.transport().RoundTrip(req)

	lt.logger.Println(req.Method, req.URL, res.StatusCode)

	return res, err
}

func (lt *loggingTransport) CancelRequest(req *http.Request) {
	type cancelableTransport interface {
		CancelRequest(*http.Request)
	}
	if cr, ok := lt.transport().(cancelableTransport); ok {
		cr.CancelRequest(req)
	}
}

func NewLoggingTransport(transport http.RoundTripper, logger *log.Logger) *loggingTransport {
	return &loggingTransport{
		Transport: transport,
		logger:    logger,
	}
}
