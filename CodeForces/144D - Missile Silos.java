import java.awt.List;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.Vector;

public class Main {

    static Vector<Vector<Pair>> adjlst = new Vector<Vector<Pair>>();
    static long dest[] = null;
    static int n, m, s;

    static void dijkstra() {
        for (int i = 0; i < dest.length; i++) {
            dest[i] = 1 << 27;
        }
        dest[s] = 0;
        PriorityQueue<Pair> q = new PriorityQueue<Pair>();
        q.add(new Pair(0, s));
        while (q.size() > 0) {
            int src = q.peek().node;
            long cost = q.peek().cost;
            q.poll();
            if (dest[src] != cost)
                continue;

            for (Pair nxt : adjlst.get(src)) {
                if (dest[nxt.node] > dest[src] + nxt.cost) {
                    dest[nxt.node] = dest[src] + nxt.cost;
                    q.add(new Pair(cost + nxt.cost, nxt.node));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader cin = new BufferedReader(
                new InputStreamReader(System.in));
        StringTokenizer tok = new StringTokenizer(cin.readLine());
        n = Integer.parseInt(tok.nextToken());
        m = Integer.parseInt(tok.nextToken());
        s = Integer.parseInt(tok.nextToken());
        int f, t, w;
        adjlst.setSize(n + 1);
        for (int i = 0; i < adjlst.size(); i++) {
            adjlst.set(i, new Vector<Pair>());
        }

        dest = new long[n + 1];
        Vector<Edge> edg = new Vector<Edge>();
        edg.setSize(m);
        for (int i = 0; i < m; i++) {
            tok = new StringTokenizer(cin.readLine());
            f = Integer.parseInt(tok.nextToken());
            t = Integer.parseInt(tok.nextToken());
            w = Integer.parseInt(tok.nextToken());
            adjlst.get(f).addElement(new Pair(w, t));
            adjlst.get(t).addElement(new Pair(w, f));
            edg.set(i, new Edge(f, t, w));
        }
        tok = new StringTokenizer(cin.readLine());
        int l = Integer.parseInt(tok.nextToken());
        dijkstra();
        for (int i = 1; i < dest.length; i++) {
            System.err.println(i + " " + dest[i]);
        }
        int res = 0;
        for (int i = 1; i < dest.length; i++) {
            if (dest[i] == l)
                ++res;
        }
        for (Edge edge : edg) {
            if (dest[edge.u] < l && dest[edge.u] + edge.w > l) {
                int req = (int) (l - dest[edge.u]);
                int other = edge.w - req;
                if (dest[edge.v] + other >= l)
                    ++res;
            }

            if (dest[edge.v] < l && dest[edge.v] + edge.w > l) {
                int req = (int) (l - dest[edge.v]);
                int other = edge.w - req;
                if(dest[edge.u] + other > l)
                    ++res;
                
            }

//          if (dest[edge.v] < l && dest[edge.u] < l) {
//              int requ = (int) (l - dest[edge.u]);
//              int reqv = (int) (l - dest[edge.v]);
//              if (requ + reqv == edge.w)
//                  --res;
//          }
        }

        System.out.println(res);
    }
}

class Edge {
    int u, v, w;

    public Edge(int u, int v, int w) {
        this.u = u;
        this.v = v;
        this.w = w;
    }
}

class Pair implements Comparable<Pair> {

    public int node;
    public long cost;

    public Pair(long cost, int nxt) {
        this.node = nxt;
        this.cost = cost;
    }

    public int compareTo(Pair o) {
        if (cost < o.cost)
            return -1;
        if (cost > o.cost)
            return 1;
        return 0;
    }

}
