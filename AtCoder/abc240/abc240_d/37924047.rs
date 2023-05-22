// detail: https://atcoder.jp/contests/abc240/submissions/37924047
use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [i64; n],
    }

    // (Ai, 連続するAiの個数)
    let mut stack: Vec<(i64, i64)> = Vec::new();
    for i in 0..n {
        if stack.is_empty() {
            stack.push((a[i].clone(), 1));
            println!("{}", stack.len());
            continue;
        }

        // insert
        {
            let (last_ai, count) = stack[stack.len() - 1].clone();
            if a[i] == last_ai {
                stack.push((a[i].clone(), count + 1))
            } else {
                stack.push((a[i].clone(), 1))
            }
        }

        // pop
        let (last_ai, count) = stack[stack.len() - 1].clone();
        if last_ai == count {
            for _ in 0..last_ai {
                stack.pop();
            }
        }
        println!("{}", stack.len());
    }
}
