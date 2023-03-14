// detail: https://atcoder.jp/contests/arc042/submissions/39729517
package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

func (p *Point) Add(p2 *Point) *Point {
	return &Point{p.x + p2.x, p.y + p2.y}
}

func (p *Point) Sub(p2 *Point) *Point {
	return &Point{p.x - p2.x, p.y - p2.y}
}

func (p *Point) Mul(n float64) *Point {
	return &Point{p.x * n, p.y * n}
}

func (p *Point) Div(n float64) *Point {
	return &Point{p.x / n, p.y / n}
}

type Segment struct {
	p1, p2 *Point
}

func norm(p *Point) float64 {
	return p.x*p.x + p.y*p.y
}

func dot(p1, p2 *Point) float64 {
	return (p1.x * p2.x) + (p1.y * p2.y)
}

func cross(p1, p2 *Point) float64 {
	return (p1.x * p2.y) - (p1.y * p2.x)
}

const epsilon = 1e-7

type Sign int

const (
	Positive Sign = iota
	Negative
	Zero
)

func sign(a float64) Sign {
	if a > epsilon {
		return Positive
	} else if a < -epsilon {
		return Negative
	} else {
		return Zero
	}
}

type CCWStatus int

const (
	Clockwise CCWStatus = iota
	CounterClockwise
	OnLineFront
	OnLineBack
	OnSegment
)

func (c CCWStatus) String() string {
	switch c {
	case Clockwise:
		return "Clockwise"
	case CounterClockwise:
		return "CounterClockwise"
	case OnLineFront:
		return "OnLineFront"
	case OnLineBack:
		return "OnLineBack"
	case OnSegment:
		return "OnSegment"
	}
	return "Unknown"
}

func ccw(s *Segment, p *Point) CCWStatus {
	origin := s.p1
	a := s.p2.Sub(origin)
	b := p.Sub(origin)

	if sign(cross(a, b)) == Positive {
		return CounterClockwise
	}

	if sign(cross(a, b)) == Negative {
		return Clockwise
	}

	if sign(dot(a, b)) == Negative {
		return OnLineBack
	}

	if norm(a) < norm(b) {
		return OnLineFront
	}

	return OnSegment
}

func projection(s *Segment, p *Point) *Point {
	a := s.p1
	b := s.p2
	segmentRatio := dot(p.Sub(a), b.Sub(a)) / norm(b.Sub(a))
	return a.Add(b.Sub(a).Mul(segmentRatio))
}

func abs(p *Point) float64 {
	return math.Sqrt(norm(p))
}

func distancePP(p1, p2 *Point) float64 {
	return abs(p1.Sub(p2))
}

func min(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

func distanceSP(s *Segment, p *Point) float64 {
	proj := projection(s, p)
	if ccw(s, proj) == OnSegment {
		return distancePP(p, proj)
	}

	dist1 := distancePP(p, s.p1)
	dist2 := distancePP(p, s.p2)
	return min(dist1, dist2)
}

func main() {
	var x, y float64
	fmt.Scan(&x, &y)

	var n int
	fmt.Scan(&n)

	pointList := make([]*Point, n)
	for i := range pointList {
		var xi, yi float64
		fmt.Scan(&xi, &yi)

		pointList[i] = &Point{xi, yi}
	}

	pointList = append(pointList, pointList[0])

	segmentList := make([]*Segment, len(pointList)-1)
	for i := 0; i < len(segmentList); i++ {
		p1 := pointList[i]
		p2 := pointList[i+1]

		segmentList[i] = &Segment{p1, p2}
	}

	minDist := math.MaxFloat64
	for _, s := range segmentList {
		minDist = min(minDist, distanceSP(s, &Point{x, y}))
	}

	fmt.Println(minDist)
}
