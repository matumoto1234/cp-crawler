// detail: https://atcoder.jp/contests/abc042/submissions/45442800
const stdInput = (): string => require("fs").readFileSync("/dev/stdin", "utf8");

function main() {
  const input = stdInput();
  const abc = input.trim().split(" ");
  abc.sort();

  if (abc[0] === "5" && abc[1] === "5" && abc[2] === "7") {
    console.log("YES");
  } else {
    console.log("NO");
  }
}

main();
