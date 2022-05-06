package model

import (
	"os"
	"fmt"
)

type Logger interface {
	Print(...any) (int, error)
	Println(...any) (int, error)
	Printf(string, ...any) (int, error)
	Fatal(...any)
	Fatalln(...any)
	Fatalf(string, ...any)
}

type loggerImpl struct {
	prefix string
}

func (l *loggerImpl) Print(a ...any) (int, error) {
	fmt.Print(l.prefix)
	return fmt.Print(a...)
}

func (l *loggerImpl) Println(a ...any) (int, error) {
	fmt.Print(l.prefix)
	return fmt.Println(a...)
}

func (l *loggerImpl) Printf(format string, a ...any) (int, error) {
	fmt.Print(l.prefix)
	return fmt.Print(fmt.Sprintf(format, a...))
}

func (l *loggerImpl) Fatal(a ...any) {
	l.Print(a...)
	os.Exit(1)
}

func (l *loggerImpl) Fatalln(a ...any) {
	l.Println(a...)
	os.Exit(1)
}

func (l *loggerImpl) Fatalf(format string, a ...any) {
	l.Printf(format, a...)
	os.Exit(1)
}

func NewLogger(prefix string) Logger {
	return &loggerImpl{
		prefix: prefix,
	}
}

func NewInfoLogger() Logger {
	return &loggerImpl{
		prefix: "[info]: ",
	}
}
