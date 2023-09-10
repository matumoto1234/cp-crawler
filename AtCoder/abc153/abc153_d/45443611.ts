// detail: https://atcoder.jp/contests/abc153/submissions/45443611
const stdInput = (): string => require("fs").readFileSync("/dev/stdin", "utf8");

function main() {
  const input = stdInput();
  let h = parseInt(input.trim());

  let turn = 1;
  while (h !== 1) {
    turn = turn + turn + 1;
    h = Math.floor(h / 2);
  }

  console.log(turn);
}

main();
