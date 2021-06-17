package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func solve() {
	var a []int64
	nextIntSlice(&a)

	a = sortSlice(a)
	max := sum(a[:4]...)
	min := sum(a[1:]...)

	writeIntSlice([]int64{min, max})
}

var (
	reader = bufio.NewReaderSize(os.Stdin, 1e9)
	writer = bufio.NewWriter(os.Stdout)
)

func nextLine() string {
	buf := make([]byte, 0)
	for {
		l, p, e := reader.ReadLine()
		if e != nil {
			panic(e)
		}
		buf = append(buf, l...)
		if !p {
			break
		}
	}
	return string(buf)
}

func nextStr(vars ...*string) {
	str := strings.Split(nextLine(), " ")
	for i, v := range vars {
		*v = str[i]
	}
}

func nextIntSlice(s *[]int64) {
	nums := strings.Split(nextLine(), " ")

	(*s) = make([]int64, len(nums))
	for i, v := range nums {
		(*s)[i], _ = strconv.ParseInt(v, 10, 64)
	}
}

func nextStrSlice(s *[]string) {
	str := strings.Split(nextLine(), " ")

	(*s) = make([]string, len(str))
	for i, v := range str {
		(*s)[i] = v
	}
}

func sortSlice(s []int64) []int64 {
	sort.Slice(s, func(i, j int) bool {
		return s[i] > s[j]
	})
	return s
}

func reverse(s []int) []int {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	return s
}

func max(A ...int) int {
	n := A[0]
	for _, v := range A {
		if n < v {
			n = v
		}
	}
	return n
}

func min(A ...int) int {
	n := A[0]
	for _, v := range A {
		if n > v {
			n = v
		}
	}
	return n
}

func sum(A ...int64) int64 {
	var sum int64 = 0
	for _, v := range A {
		sum += v
	}
	return sum
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

func write(s ...interface{}) {
	fmt.Fprintln(writer, s...)
}

func writeIntSlice(s []int64) {
	output := make([]interface{}, len(s))
	for i, v := range s {
		output[i] = v
	}
	fmt.Fprintln(writer, output...)
}

func main() {
	defer writer.Flush()
	solve()
}
