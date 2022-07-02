template <int char_size>
struct TrieNode {
    array<int, char_size> nxt;

    int exist;
    vector<int> accept;

    TrieNode() : exist(0) { fill(nxt.begin(), nxt.end(), -1); }
};

template <int char_size, int margin>
struct Trie {
    using Node = TrieNode<char_size>;

    vector<Node> nodes;
    int root, node_ptr;

    void expand() {
        int sz = nodes.size();
        nodes.resize(sz * 2);
    }

    Trie() : root(0), node_ptr(1) { nodes.push_back(Node()); }

    void update_direct(int node, int id) { nodes[node].accept.push_back(id); }

    void update_child(int node, int child, int id) { ++nodes[node].exist; }

    void add(const string &str, int str_index, int node_index, int id) {
        if (str_index == str.size()) {
            update_direct(node_index, id);
        } else {
            const int c = str[str_index] - margin;
            if (nodes[node_index].nxt[c] == -1) {
                int nxt_id = node_ptr++;
                nodes[node_index].nxt[c] = nxt_id;
                if (nxt_id >= nodes.size()) expand();
            }

            add(str, str_index + 1, nodes[node_index].nxt[c], id);
            update_child(node_index, nodes[node_index].nxt[c], id);
        }
    }

    void add(const string &str, int id) { add(str, 0, 0, id); }
    void add(const string &str) { add(str, nodes[0].exist); }

    int count() const { return nodes[0].exist; }
};