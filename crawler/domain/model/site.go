package domain

// Value object
type Site string

const (
	SiteAtcoder Site = "atcoder"
)

func (s Site) String() string {
	switch s {
	case SiteAtcoder:
		return "AtCoder"
	default:
		return "Unknown site"
	}
}
