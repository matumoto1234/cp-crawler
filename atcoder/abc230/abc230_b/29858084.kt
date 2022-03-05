// detail: https://atcoder.jp/contests/abc230/submissions/29858084
fun main(args: Array<String>) {
  val s:String = readLine()!!
  val t:String = "oxx".repeat(100000)
  
  var ans:Boolean = false
  
  for(i in 0 until t.length) {
    if (i + s.length - 1 >= t.length) {
      break
    }

    var is_same:Boolean = true
    for(j in 0 until s.length) {
      if (t[i+j] != s[j]) {
        is_same = false
        break
      }
    }

    if (is_same) {
      ans = true
    }
  }

  if (ans) {
    println("Yes")
  } else {
    println("No")
  }
}
