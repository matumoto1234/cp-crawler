package infra

import (
	"net/http"

	"golang.org/x/time/rate"
)

type RateLimitTransport struct {
	Transport   http.RoundTripper
	rateLimiter *rate.Limiter
}

func (rlt *RateLimitTransport) transport() http.RoundTripper {
	if rlt.Transport == nil {
		return http.DefaultTransport
	}
	return rlt.Transport
}

func (rlt *RateLimitTransport) RoundTrip(req *http.Request) (*http.Response, error) {
	res, err := rlt.transport().RoundTrip(req)

	if err := rlt.rateLimiter.Wait(req.Context()); err != nil {
		return nil, err
	}

	return res, err
}

func (rlt *RateLimitTransport) CancelRequest(req *http.Request) {
	type canceler interface {
		CancelRequest(*http.Request)
	}
	if cr, ok := rlt.transport().(canceler); ok {
		cr.CancelRequest(req)
	}
}

func NewRateLimitTransport(transport http.RoundTripper, rateLimiter *rate.Limiter) *RateLimitTransport {
	return &RateLimitTransport{
		Transport:   transport,
		rateLimiter: rateLimiter,
	}
}
