class find_using_recursion {
    public static int[] par = new int[1005];

    public static int find(int node) {
        if (par[node] == -1)
            return node;
        int leader = find(par[node]);
        par[node] = leader;
        return leader;
    }

    public static void main(String[] args) {
        for (int i = 0; i < par.length; i++)
            par[i] = -1;
        par[0] = 1;
        par[1] = -1;
        par[2] = 1;
        par[3] = 1;
        par[4] = 5;
        par[5] = 3;
        System.out.println(find(4));

        for (int i = 0; i < 6; i++)
            System.out.printf("%d -> %d\n", i, par[i]);
    }
}