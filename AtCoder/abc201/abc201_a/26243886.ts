// detail: https://atcoder.jp/contests/abc201/submissions/26243886
'use strict';

const permutations = (array: number[]): number[][] => {
  const result: number[][] = new Array();

  for(let i: number = 0; i < array.length; i++){
    const array2 = array.slice(0);
    array2.splice(i, 1);

    for(let j: number = 0; j < array2.length; j++) {
      const array3 = array2.slice(0);
      array3.splice(j, 1);

      for(let k: number = 0; k < array3.length; k++){
        result.push([array[i]].concat([array2[j]]).concat([array3[k]]));
      }
    }
  }
  return result;
}

const isValid = (A: number, B: number, C: number): boolean => {
  return C - B === B - A;
}

const main = (arg: string) => {
  const input: string[] = arg.trim().split('\n');

  let As: number[] = input[0].split(' ').map(A => parseInt(A));

  As = As.sort();

  const ps: number[][] = permutations(As);

  let answer: boolean = false;
  for (let i: number = 0; i < ps.length; i++) {
    if (isValid(ps[i][0], ps[i][1], ps[i][2])) {
      answer = true;
    }
  }

  if (answer) {
    console.log('Yes');
  } else {
    console.log('No');
  }
};
main(require('fs').readFileSync('/dev/stdin', 'utf8'));