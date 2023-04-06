// detail: https://atcoder.jp/contests/abc203/submissions/26245168
'use strict';

class pairInt {
  first: number;
  second: number;

  constructor(f: number, s: number) {
    this.first = f;
    this.second = s;
  }

  equals(other: pairInt): boolean {
    return this.first === other.first && this.second === other.second;
  }
}

const compare = (a: pairInt, b: pairInt): number => {
  if (a.equals(b)) return 0
  if (a.first !== b.first) {
    if (a.first < b.second) return -1;
    return 1;
  }
  if (a.second < b.second) return -1;
  return 1;
};

const main = (arg: string) => {
  const input: string[] = arg.trim().split('\n');

  const [N, K] = input[0].split(' ').map(x => parseInt(x));

  // let ABs: pairInt[] = new Array();
  let ABs: Array<pairInt> = [];

  for (let i: number = 0; i < N; i++) {
    const A: number = parseInt(input[i + 1].split(' ')[0]);
    const B: number = parseInt(input[i + 1].split(' ')[1]);
    ABs.push(new pairInt(A, B));
  }

  ABs.sort(compare);

  let answer: number = 0;
  let last: number = 0;
  let money: number = K;
  let flg: boolean = false;
  for (let i: number = 0; i < N; i++) {
    const A: number = ABs[i].first;
    const B: number = ABs[i].second;

    if (money < A - last) {
      answer = last + money;
      money = 0;
      flg = true;
      break;
    }

    money -= A - last;
    last = A;
    money += B;
  }

  if (!flg) {
    answer = K;
    for (let i = 0; i < N; i++) {
      const A: number = ABs[i].first;
      const B: number = ABs[i].second;
      answer += B;
    }
  }

  console.log(answer);
};
main(require('fs').readFileSync('/dev/stdin', 'utf8'));