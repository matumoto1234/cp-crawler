// detail: https://atcoder.jp/contests/abc044/submissions/45442999
const stdInput = (): string => require("fs").readFileSync("/dev/stdin", "utf8");

function main() {
  const input = stdInput();
  const lines = input.trim().split("\n");

  const n = parseInt(lines[0])
  const k = parseInt(lines[1])
  const x = parseInt(lines[2])
  const y = parseInt(lines[3])

  let sum = 0;

  for (let i=1; i<=n; i++) {
    if(i<=k){
      sum += x;
    }else{
      sum += y;
    }
  }

  console.log(sum);
}

main();
