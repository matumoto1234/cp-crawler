// detail: https://atcoder.jp/contests/APG4b/submissions/37124874
fn main() {
  // 変数a,b,cにtrueまたはfalseを代入してAtCoderと出力されるようにする。
  let a = true;
  let b = false;
  let c = true;

  // ここから先は変更しないこと

  if a {
    print!("At");
  }
  else {
    print!("Yo");
  }

  if !a && b {
    print!("Bo");
  }
  else if !b || c {
    print!("Co");
  }

  if a && b && c {
    print!("foo!");
  }
  else if true && false {
    print!("yeah!");
  }
  else if !a || c {
    print!("der");
  }

  println!();
}