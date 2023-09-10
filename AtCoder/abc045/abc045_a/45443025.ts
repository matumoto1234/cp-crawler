// detail: https://atcoder.jp/contests/abc045/submissions/45443025
const stdInput = (): string => require("fs").readFileSync("/dev/stdin", "utf8");

function main() {
  const input = stdInput();
  const lines = input.trim().split("\n");

  const a = parseInt(lines[0]);
  const b = parseInt(lines[1]);
  const h = parseInt(lines[2]);

  console.log(((a + b) * h) / 2);
}

main();
