import scala.math._
import scala.collection.mutable.{Map => MMap}
import scala.util.control.Breaks._

class Dijkstra(map: MMap[Int, MMap[Int, Double]]) {
  val INFINITY = 1.0/0

  var disL: Int = 0
  val dis = MMap[Int, Double]()
  val mark = MMap[Int, Boolean]()

  def init(c: Int) {
    si(c)
    for(i <- 0 until disL) {
      dis += (i -> INFINITY)
    }
    for(i <- 0 until c) {
      mark += (i -> false)
    }
  }

  def lowbit(x: Int): Int = x&(-x)

  def si(c: Int) {
    var cc = c
    while(lowbit(cc) != cc) {
      cc += lowbit(cc)
    }
    disL = cc
  }

  def createIndex() {
    for( i <- 0 until 2 * disL - 1) {
      dis += (i -> INFINITY)
    }
  }

  def updateIndex(index: Int, value: Double) {
    var i = index + disL - 1
    dis += (i -> value)

    while (i > 0) {
      val pi = (i - 1) / 2
      val pv = min(dis(pi * 2 + 1), dis(pi * 2 + 2));
      if (dis(pi) == pv) {
        return
      }
      dis += (pi -> pv)
      i = pi
    }
  }

  def getMinIndex(): Int = {
    var x = 0;
    while(x < disL - 1) {
      if(dis(x) == dis(x * 2 + 1)) {
        x = x * 2 + 1;
      } else {
        x = x * 2 + 2;
      }
    }
    x - (disL - 1);
  }

  def cacul(src: Int, tar: Int): Double = {
    createIndex()
    updateIndex(src, 0)
    var result = INFINITY
    while(dis(0) != INFINITY) {
      val k = getMinIndex()
      val v = dis(0)
      mark += (k -> true)
      updateIndex(k, INFINITY)
      if (k == tar) {
        result = v
      }
      map.get(k) match {
        case Some(x) =>
          for(p <- x) {
            if(!mark(p._1)) {
              val t = p._2 + v
              if(dis(p._1 + disL - 1) > t) {
                updateIndex(p._1, t)
              }
            }
          }
        case None =>
      }

    }
    result
  }

}
