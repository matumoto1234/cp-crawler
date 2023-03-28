package usecase

type ErrKind int

const (
	ErrCrawlerError ErrKind = iota + 1
	ErrRepositoryError
)

// Error : Error struct for usecase layer
type Error struct {
	Err  error   // error(wrapped error)
	Kind ErrKind // kind of error
}

func NewError(err error, kind ErrKind) *Error {
	return &Error{
		Err:  err,
		Kind: kind,
	}
}

// Error : get error message
func (e Error) Error() string {
	return e.Err.Error()
}
