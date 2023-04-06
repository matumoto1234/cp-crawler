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

func (t *rateLimitTransport) transport() http.RoundTripper {
	if t.Transport == nil {
		return http.DefaultTransport
	}
	return t.Transport
}

func (t *rateLimitTransport) RoundTrip(req *http.Request) (*http.Response, error) {
	res, err := t.transport().RoundTrip(req)

	if err := t.rateLimiter.Wait(req.Context()); err != nil {
		return nil, err
	}

	return res, err
}

func (t *rateLimitTransport) CancelRequest(req *http.Request) {
	type cancelableTransport interface {
		CancelRequest(*http.Request)
	}
	if cr, ok := t.transport().(cancelableTransport); ok {
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

func (t *loggingTransport) transport() http.RoundTripper {
	if t.Transport == nil {
		return http.DefaultTransport
	}
	return t.Transport
}

func (t *loggingTransport) RoundTrip(req *http.Request) (*http.Response, error) {
	res, err := t.transport().RoundTrip(req)

	t.logger.Println(req.Method, req.URL, res.StatusCode)

	return res, err
}

func (t *loggingTransport) CancelRequest(req *http.Request) {
	type cancelableTransport interface {
		CancelRequest(*http.Request)
	}
	if cr, ok := t.transport().(cancelableTransport); ok {
		cr.CancelRequest(req)
	}
}

func NewLoggingTransport(transport http.RoundTripper, logger *log.Logger) *loggingTransport {
	return &loggingTransport{
		Transport: transport,
		logger:    logger,
	}
}
