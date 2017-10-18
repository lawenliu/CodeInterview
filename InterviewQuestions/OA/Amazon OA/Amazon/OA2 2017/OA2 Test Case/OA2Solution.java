//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% WINDOW SUM
public class WindowSum {
    
    public List<Integer> windowSum(int[] nums, int windowSize) {
        List<Integer> result = new ArrayList<Integer>();
        
        // corner cases, return the original numbers
        if (windowSize < 1 || windowSize > nums.length) {
            for (int i : nums)
                result.add(i);
            return result;
        }
        
        // for each window
        for (int i = 0; i < nums.length - windowSize + 1; i++) {
            // in each window
            int windowSum = 0;
            for (int j = i; j < i + windowSize; j++) {
                windowSum += nums[j];
            }
            result.add(windowSum);
        }
        
        return result;
    }
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% RECTANGLE OVERLAP
class RectanglePoint {
    int x;
    int y;
    
    public RectanglePoint(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Rectangle {
    RectanglePoint topLeft;
    RectanglePoint bottomRight;
    
    public Rectangle(RectanglePoint topLeft, RectanglePoint bottomRight) {
        this.topLeft = topLeft;
        this.bottomRight = bottomRight;
    }
}

public class RectangleOverlap {
    
    private boolean isOverlap(Rectangle r1, Rectangle r2) {
        
        // if one rectangle is at the other rectangle's left
        if (r1.bottomRight.x < r2.topLeft.x || r2.bottomRight.x < r1.topLeft.x)
            return false;
        
        // if one rectangle is at the other rectangle's top
        if (r1.bottomRight.y > r2.topLeft.y || r2.bottomRight.y > r1.topLeft.y)
            return false;
        
        return true;
    }
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% K CLOSEST POINTS
class Point {
    double x;
    double y;
    
    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
}

public class KClosestPoints {
    
    private Point[] getKNearestPoints(Point[] points, int k) {
        // result to be returned with a size of k
        int resultLength = Math.min(k, points.length);
        Point[] result = new Point[resultLength];
        if (k < 1)
            return result;
        
        // a priority queue to store given points
        PriorityQueue<Point> pq = new PriorityQueue<Point>(k, new Comparator<Point>() {
            
            @Override
            public int compare(Point p1, Point p2) {
                double d1 = Math.sqrt(Math.pow(p1.x, 2) + Math.pow(p1.y, 2));
                double d2 = Math.sqrt(Math.pow(p2.x, 2) + Math.pow(p2.y, 2));
                
                if (d1 > d2)
                    return 1;
                else if (d1 == d2)
                    return -1;
                else
                    return -1;
            }
            
        });
        
        // add points into priority queue
        for (Point aPoint : points) {
            pq.add(aPoint);
        }
        
        // take nearest k points from pq to result
        for (int i = 0; i < resultLength; i++) {
            result[i] = pq.poll();
        }
        
        return result;
    }
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% LONGEST PALINDROME
public class LongestPalindrome {
    
    private static String longestPalindrome(String s) {
        String result = "";
        int curLength = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (isPalindrome(s, i - curLength - 1, i)) {
                result = s.substring(i - curLength - 1, i + 1);
                curLength += 2;
            }
            if (isPalindrome(s, i - curLength, i)) {
                result = s.substring(i - curLength, i + 1);
                curLength += 1;
            }
        }
        return result;
    }
    
    private static boolean isPalindrome(String s, int i, int j) {
        if (i < 0)
            return false;
        while (i < j)
            if (s.charAt(i++) != s.charAt(j--))
                return false;
        return true;
    }
    
    public static void main(String[] args) {
        String test1 = "abcdefeghij";
        String ansr1 = longestPalindrome(test1);
        System.out.printf("Given string \"%s\", result = %s\n", test1, ansr1);
    }
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% DEEP COPY
class RandomListNode {
    int label;
    RandomListNode next, random;
    
    RandomListNode(int x) {
        this.label = x;
    }
}

public class DeepCopy {
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null)
            return null;
        
        Map<RandomListNode, RandomListNode> map = new HashMap<RandomListNode, RandomListNode>();
        RandomListNode dummy = new RandomListNode(-1);
        RandomListNode cur = head, curNew = dummy;
        while (cur != null) {
            if (!map.containsKey(cur))
                map.put(cur, new RandomListNode(cur.label));
            if (cur.random != null && !map.containsKey(cur.random))
                map.put(cur.random, new RandomListNode(cur.random.label));
            
            curNew.next = map.get(cur);
            curNew.next.random = map.get(cur.random);
            curNew = curNew.next;
            cur = cur.next;
        }
        
        return dummy.next;
    }
    
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% ORDER DEPENDENCY
class Order {
    String orderName;
    
    public Order(String string) {
        this.orderName = string;
    }
}

class OrderDependency {
    Order cur;
    Order pre;
    
    public OrderDependency(Order pre, Order cur) {
        this.pre = pre;
        this.cur = cur;
    }
}

public class OrderDependancy {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] incLinkCounts = new int[numCourses];
        List<List<Integer>> graph = new ArrayList<>(numCourses);
        buildGraph(graph, incLinkCounts, prerequisites);
        return solveByBFS(graph, incLinkCounts);
    }
    
    private void buildGraph(List<List<Integer>> graph, int[] incLinkCounts, int[][] prerequisites) {
        
        // initialize the graph
        for (int i = 0; i < incLinkCounts.length; i++) {
            graph.add(new ArrayList<>());
        }
        
        // build the graph and increase prerequisite count
        for (int[] edge : prerequisites) {
            graph.get(edge[1]).add(edge[0]);
            incLinkCounts[edge[0]]++;
        }
    }
    
    private int[] solveByBFS(List<List<Integer>> graph, int[] incLinkCounts) {
        int[] order = new int[incLinkCounts.length];
        
        // initialize which node to visit first
        Queue<Integer> nextVisit = new ArrayDeque<>();
        for (int i = 0; i < incLinkCounts.length; i++) {
            if (incLinkCounts[i] == 0)
                nextVisit.offer(i);
        }
        
        // visit nodes that have no prerequisite
        int nextVisitIndex = 0;
        while (!nextVisit.isEmpty()) {
            int from = nextVisit.poll();
            order[nextVisitIndex++] = from;
            
            // decrement incLinkCounts
            for (int to : graph.get(from)) {
                incLinkCounts[to]--;
                if (incLinkCounts[to] == 0) {
                    nextVisit.offer(to);
                }
            }
        }
        
        return nextVisitIndex == incLinkCounts.length ? order : new int[0];
    }
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% MST
public class MinimumSpanningTree {
    private static List<Connection> findPath(ArrayList<Connection> cityList) {
        // result to be returned
        ArrayList<Connection> result = new ArrayList<Connection>();
        // to keep track of visited cities
        ArrayList<String> cityTree = new ArrayList<String>();
        
        while (!cityList.isEmpty()) {
            // find the minimum cost to the city from cityTree among the result
            Connection temp = findMin(cityList, cityTree);
            if (temp == null) {
                break;
            }
            cityList.remove(temp);
            cityTree.add(temp.city1);
            cityTree.add(temp.city2);
            result.add(temp);
        }
        
        Comparator<Connection> cmp = new Comparator<Connection>() {
            
            @Override
            public int compare(Connection o1, Connection o2) {
                if (o1.city1.equals(o2.city1))
                    return o1.city2.compareTo(o2.city2);
                return o1.city1.compareTo(o2.city2);
            }
            
        };
        result.sort(cmp);
        
        return result;
    }
    
    private static Connection findMin(ArrayList<Connection> cityList, ArrayList<String> cityTree) {
        Connection result = null;
        int minCost = Integer.MAX_VALUE;
        
        for (Connection con: cityList) {
            if (con.cost <= minCost) {
                if (cityTree.contains(con.city1) && !cityTree.contains(con.city2)) {
                    minCost = con.cost;
                    result = con;
                }
                if (cityTree.isEmpty()) {
                    minCost = con.cost;
                    result = con;
                }
            }
        }
        return result;
    }
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% HIGH FIVE
class Result {
    int id;
    int value;
    
    public Result(int id, int value) {
        this.id = id;
        this.value = value;
    }
}

public class HighFive {
    public Map<Integer, Double> getHighFive(Result[] resultArray) {
        // write your code here
        
        // toReturn is storing the resulting student and highest average five scores
        // pairs
        Map<Integer, Double> toReturn = new HashMap<Integer, Double>();
        
        // scores is storing student and all scores
        Map<Integer, ArrayList<Integer>> allScores = new HashMap<Integer, ArrayList<Integer>>();
        
        // insert all scores in allScores
        for (Result aResult : resultArray) {
            // if student record existed
            if (allScores.containsKey(aResult.id)) {
                ArrayList<Integer> tmpList = allScores.get(aResult.id);
                tmpList.add(aResult.value);
                allScores.put(aResult.id, tmpList);
            }
            // if not previously existed
            else {
                ArrayList<Integer> tmpList = new ArrayList<Integer>();
                tmpList.add(aResult.value);
                allScores.put(aResult.id, tmpList);
            }
        }
        
        for (Integer aStudentID : allScores.keySet()) {
            ArrayList<Integer> tmpList = allScores.get(aStudentID);
            Collections.sort(tmpList);
            Collections.reverse(tmpList);
            double highFive = 0;
            for (int i = 0; i < 5; i++) {
                highFive += tmpList.get(i);
            }
            toReturn.put(aStudentID, highFive / 5);
        }
        
        return toReturn;
    }
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% MAXIMUM SUBTREE
class Node { // 这个是题目给好的
    int val;
    ArrayList<Node> children;
    
    public Node(int val) {
        this.val = val;
        children = new ArrayList<Node>();
    }
}

// 这个类是自己写的,要不不好找,两个成员变量分别是当前的总和和人数
class SumCount {
    int sum;
    int count;
    
    public SumCount(int sum, int count) {
        this.sum = sum;
        this.count = count;
    }
}

public class CompanyTree {
    // 两个全局变量用来找最小的平均值,和对应的节点
    private static double resAve = Double.MIN_VALUE;
    private static Node result;
    
    public static Node getHighAve(Node root) {
        if (root == null)
            return null;
        dfs(root);
        return result;
    }
    
    // 后序遍历递归。
    private static SumCount dfs(Node root) {
        if (root.children == null || root.children.size() == 0) {
            //System.out.printf("return node: %d\n", root.val);
            return new SumCount(root.val, 1);
        }
        
        int curSum = root.val;
        int curCnt = 1;
        
        for (Node child : root.children) {
            SumCount childStat = dfs(child);
            curSum += childStat.sum;
            curCnt += childStat.count;
        }
        
        double curAve = (double) curSum / curCnt;
        
        if (resAve < curAve) {
            resAve = curAve;
            result = root;
        }
        
        //System.out.printf("return node: %d\n", root.val);
        return new SumCount(curSum, curCnt);
    }
}
