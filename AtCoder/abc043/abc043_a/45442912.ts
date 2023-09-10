// detail: https://atcoder.jp/contests/abc043/submissions/45442912
const stdInput = (): string => require("fs").readFileSync("/dev/stdin", "utf8");

function main() {
  const input = stdInput();
  const n = parseInt(input.trim());
  console.log(((1 + n) * n) / 2);
}

main();
