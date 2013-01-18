import scala.collection.mutable.{Map => MMap}

class Graph {
  val map = MMap[Int, MMap[Int, Double]]()
  val nodes = MMap[Symbol, Int]()
  var index = 0;

  def get(startNode: Int, endNode: Int): Double = {
    try {
      map(startNode)(endNode)
    } catch {
      case _ => -1
    }
  }

  def set(startNode: Symbol, endNode: Symbol, cost: Double) {
    val startIndex = nodes.get(startNode) match {
      case Some(i) => i
      case None =>
        nodes += (startNode -> index)
        index += 1
        index - 1
    }
    val endIndex = nodes.get(endNode) match {
      case Some(i) => i
      case None =>
        nodes += (endNode -> index)
        index += 1
        index - 1
    }

    map.get(startIndex) match {
      case Some(m) => m += (endIndex -> cost)
      case None => map += (startIndex -> MMap(endIndex -> cost))
    }
  }

  def doFind(startNode: Symbol, endNode: Symbol) {
    val dijkstra = new Dijkstra(map)
    dijkstra.init(index)
    val distance = dijkstra.cacul(nodes(startNode), nodes(endNode))
    if (distance.isInfinite) {
      println("unrearchable")
    } else {
      println(distance.toInt)
    }
  }
}
