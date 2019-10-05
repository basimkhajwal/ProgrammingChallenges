import scala.collection.mutable
import scala.math.Ordering.IntOrdering
import scala.languageFeature.implicitConversions

object problem425 {

  def sieve(bound: Int): (Array[Boolean], Array[Int]) = {
    val isComposite = new Array[Boolean](bound)
    val primes = new mutable.ArrayBuffer[Int]()
    isComposite(0) = true
    isComposite(1) = true
    for (i <- 0 until bound) {
      if (!isComposite(i) ) {
        primes += i
        if (i <= bound/i) {
          for (j <- i*i until bound by i) isComposite(j) = true
        }
      }
    }
    (isComposite, primes.toArray)
  }

  def connections(n: Int): Array[Int] = {
    val nStr = "0" + n.toString
    val acc = new Array[Int](10 * nStr.length)
    var tenPow = 1
    for (i <- 0 until nStr.length) {
      val oldD = nStr.charAt(nStr.length - i - 1)-'0'
      for (d <- 0 to 9) acc(i*10 + d) = (n + (d - oldD) * tenPow)
      tenPow *= 10
    }
    acc
  }

  def solveF(numDigits: Int): Long = {
    val bound = Math.pow(10, numDigits).toInt
    val (isComposite, primes) = sieve(bound)

    // BFS through primes from 2, keeping track of the largest prime whose 
    // connections have currently been processed so far.
    val seen = mutable.Set[Int]()
    // Use a min PQ (default is max)
    val bfs = mutable.PriorityQueue[Int]()(implicitly[IntOrdering].reverse)
    var highestNum = 0
    var pqTotal: Long = 0
    bfs.enqueue(2)
    seen.add(2)
    while (!bfs.isEmpty) {
      val nextNum = bfs.dequeue()
      for (r <- connections(nextNum)) {
        if (r < bound && !isComposite(r) && !seen.contains(r)) {
          bfs += r
          seen += r
        }
      }
      // Only include numbers which do not require a chain
      // from higher numbers
      if (nextNum > highestNum) {
        highestNum = nextNum
        pqTotal += highestNum
      }
    }

    primes.foldLeft(0L)(_ + _) - pqTotal
  }
  
  def main(args: Array[String]): Unit = println(solveF(7))
}
