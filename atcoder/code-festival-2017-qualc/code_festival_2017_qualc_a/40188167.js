// detail: https://atcoder.jp/contests/code-festival-2017-qualc/submissions/40188167
"use strict";

const parseInput = input => {
  return input.trim().split("")
}

const solve = chars => {
  const { existAC } = chars
    .reduce(({ existA, existAC }, c) => ({
      existA: c === "A",
      existAC: existAC || (existA && (c === "C"))
    }), { existA: false, existAC: false })
  console.log(existAC ? "Yes" : "No")
}

const main = input => {
  solve(parseInput(input))
}

main(require('fs').readFileSync('/dev/stdin', 'utf8'));
