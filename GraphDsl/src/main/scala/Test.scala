object Test {
  def main(args: Array[String]) {
    println("test1")
    val test1 = new GraphDsl {
      'nodeA -- 3 --> 'nodeB
      'nodeB -- 4 --> 'nodeC
      'nodeC <-- 1 -- 'nodeD
      'nodeD <-- 2 --> 'nodeE
      path from 'nodeA to 'nodeC
      path from 'nodeA to 'nodeD
      'nodeC -- 4 --> 'nodeD
      path from 'nodeA to 'nodeD
    }
    println("test2")
    val test2 = new GraphDsl {
      'nodeA -- 13 --> 'nodeB
      'nodeB -- 2 --> 'nodeC
      'nodeC <-- 4 -- 'nodeD
      'nodeD <-- 1 --> 'nodeE
      path from 'nodeA to 'nodeC
      path from 'nodeA to 'nodeD
      'nodeC -- 8 --> 'nodeD
      path from 'nodeA to 'nodeD
    }
  }
}
