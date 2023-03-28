package domain

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
	TotalCount int
}

func NewPaging(totalCount int) Paging {
	return Paging{
		TotalCount: totalCount,
	}
}
