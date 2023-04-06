package judge

// Value object
type Status string

const (
	CompilationError    Status = "CE"
	MemoryLimitExceeded Status = "MLE"
	TimeLimitExceeded   Status = "TLE"
	RuntimeError        Status = "RE"
	OutputLimitExceeded Status = "OLE"
	InternalError       Status = "IE"
	WrongAnswer         Status = "WA"
	PresentationError   Status = "PE"
	Accepted            Status = "AC"
	WaitingForJudging   Status = "WJ"
	WaitingForRejudging Status = "WR"
	JudgeNotAvailable   Status = "JNA"
)

func (j Status) String() string {
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
