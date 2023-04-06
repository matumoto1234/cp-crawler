// detail: https://atcoder.jp/contests/arc009/submissions/26243969
'use strict';

const main = (arg: string) => {
  const input: string[] = arg.trim().split('\n');

  const N: number = parseInt(input[0]);

  let answer: number = 0

  for (let i: number = 0; i < N; i++) {
    const A: number = parseInt(input[i + 1].split(' ')[0]);
    const B: number = parseInt(input[i + 1].split(' ')[1]);
    answer += A * B;
  }

  answer = Math.floor(answer * 1.05);

  console.log(answer);
};
main(require('fs').readFileSync('/dev/stdin', 'utf8'));