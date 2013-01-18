import scala.collection.mutable.{Map => MMap}
import scala.Symbol

trait GraphDsl {

  val g = new Graph


  class Find(startNode: Symbol) {
    def to(endNode: Symbol) {
      g.doFind(startNode, endNode)
    }
  }

  val path = Path()
  case class Path() {
    def from(startNode: Symbol) = {
      new Find(startNode)
    }
  }

  implicit def asNode(n: Symbol): Node = new Node(n)
  class Node(startNode: Symbol) {
    def --(cost: Double) = new NodeWithCostX(startNode, cost)
    def <--(nwcy: NodeWithCostY) {
      g.set(nwcy.endNode, startNode, nwcy.cost)
    }
    def <--(nwry: NodeWithReverse) {
      g.set(nwry.endNode, startNode, nwry.cost)
      g.set(startNode, nwry.endNode, nwry.cost)
    }
  }

  class NodeWithCostX(startNode: Symbol, cost: Double) {
    def -->(endNode: Symbol) {
      g.set(startNode, endNode, cost)
    }
  }

  implicit def asCost(c: Int): Cost = new Cost(c.toDouble)
  class Cost(cost: Double) {
    def --(endNode: Symbol) = NodeWithCostY(endNode, cost)
    def -->(endNode: Symbol) = NodeWithReverse(endNode, cost)
  }

  case class NodeWithCostY(endNode: Symbol, cost: Double)

  case class NodeWithReverse(endNode: Symbol, cost: Double)


}
