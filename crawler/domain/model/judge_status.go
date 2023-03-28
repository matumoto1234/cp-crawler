package domain

// Value object
type JudgeStatus int

const (
	CompilationError JudgeStatus = iota
	MemoryLimitExceeded
	TimeLimitExceeded
	RuntimeError
	OutputLimitExceeded
	InternalError
	WrongAnswer
	PresentationError
	Accepted
	WaitingForJudging
	WaitingForRejudging
	JudgeNotAvailable
)

func (j JudgeStatus) String() string {
	switch j {
	case CompilationError:
		return "CompilationError"
	case MemoryLimitExceeded:
		return "MemoryLimitExceeded"
	case TimeLimitExceeded:
		return "TimeLimitExceeded"
	case RuntimeError:
		return "RuntimeError"
	case OutputLimitExceeded:
		return "OutputLimitExceeded"
	case InternalError:
		return "InternalError"
	case WrongAnswer:
		return "WrongAnswer"
	case PresentationError:
		return "PresentationError"
	case Accepted:
		return "Accepted"
	case WaitingForJudging:
		return "WaitingForJudging"
	case WaitingForRejudging:
		return "WaitingForRejudging"
	case JudgeNotAvailable:
		return "JudgeNotAvailable"
	}
	return "UnknownJudgeStatus"
}
