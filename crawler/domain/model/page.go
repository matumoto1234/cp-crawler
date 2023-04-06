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
	PageSize   int
	TotalCount int
}

func NewPaging(pageSize, totalCount int) Paging {
	return Paging{
		PageSize:   pageSize,
		TotalCount: totalCount,
	}
}
