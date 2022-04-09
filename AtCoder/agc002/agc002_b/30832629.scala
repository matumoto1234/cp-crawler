// detail: https://atcoder.jp/contests/agc002/submissions/30832629
import scala.io.StdIn.{readInt, readLine}

object Main {
  def main(argv: Array[String]): Unit = {
    val Array(n, m) = readLine().split(" ").map(_.toInt)

    val xys =
      (for (_ <- 1 to m) yield readLine())
        .map(_.split(" ").map(_.toInt))

    var is_red = Array.fill(n) { false }
    is_red(0) = true
    var ball_count = Array.fill(n) { 1 }

    for (i <- 0 until m) {
      val Array(x, y) = xys(i)
      val from = x - 1
      val to = y - 1

      ball_count(from) -= 1
      ball_count(to) += 1

      is_red(to) = is_red(to) || is_red(from)
      if (ball_count(from) == 0) {
        is_red(from) = false
      }
    }

    println(is_red.count(_ == true))
  }
}
