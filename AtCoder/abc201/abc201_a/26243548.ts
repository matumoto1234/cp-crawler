// detail: https://atcoder.jp/contests/abc201/submissions/26243548
'use strict';

const main = (arg: string) => {
  const input: string[] = arg.trim().split('\n');

  let As: number[] = input[0].split(' ').map(A => parseInt(A))

  As = As.sort()

  if (As[2] - As[1] === As[1] - As[0]) {
    console.log('Yes')
  } else {
    console.log('No')
  }
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));