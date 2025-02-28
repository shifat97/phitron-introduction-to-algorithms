public class union {
    public static int[] par = new int[1005];
    public static int[] size = new int[1005];

    public static int find(int node) {
        if (par[node] == -1)
            return node;
        int leader = find(par[node]);
        par[node] = leader;
        return leader;
    }

    public static void dsu_union(int node1, int node2) {
        int leader1 = find(node1);
        int leader2 = find(node2);
        if (size[leader1] >= size[leader2]) {
            par[leader2] = leader1;
            size[leader1] += size[leader2];
        } else {
            par[leader1] = leader2;
            size[leader2] += size[leader1];
        }
    }

    public static void main(String[] args) {
        for (int i = 0; i < par.length; i++)
            par[i] = -1;
        for (int i = 0; i < size.length; i++)
            size[i] = 1;
        dsu_union(1, 2);
        System.out.println(find(4));
        for (int i = 0; i < 6; i++)
            System.out.printf("%d -> %d\n", i, par[i]);
    }
}
