// detail: https://atcoder.jp/contests/abc203/submissions/26245377
'use strict';

const main = (arg: string) => {
  const input: Array<string> = arg.trim().split('\n');

  const [N, K] = input[0].split(' ').map(x => parseInt(x));

  let AB: Array<{A:number, B:number}> = [];

  for (let i = 0; i < N; i++) {
    AB[i] = {A:0, B:0};
    [AB[i].A, AB[i].B] = input[i + 1].split(' ').map(x => parseInt(x));
  }

  AB.sort((x, y) => x.A - y.A);

  let ans = K;
  for (let i = 0; i < N; i++) {
    if (ans < AB[i].A) break;
    ans += AB[i].B;
  }
  console.log(ans);
};
main(require('fs').readFileSync('/dev/stdin', 'utf8'));