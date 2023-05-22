package model

// Value object
type Page[T any] struct {
	ItemList []T
	Paging   Paging
}

func NewPage[T any](itemList []T, paging Paging) *Page[T] {
	return &Page[T]{
		ItemList: itemList,
		Paging:   paging,
	}
}

// Value object
type Paging struct {
	TotalCount uint
}

func NewPaging(totalCount uint) Paging {
	return Paging{
		TotalCount: totalCount,
	}
}
