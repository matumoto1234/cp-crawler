// detail: https://atcoder.jp/contests/abc134/submissions/29858187
'use strict'
function main(input) {
  input = input.split(" ");
  const N = parseInt(input[0]);
  const D = parseInt(input[1]);
  
  const len = 2*D+1;
  console.log(Math.ceil(N/len))
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));