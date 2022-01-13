// Two stacks (first solution) are natural fit for this problem. It's easier to implement during the contest. Using a single list (second solution) is faster, but it's a bit trickier to maintain the current position.

// One thing that is unclear is what should we do if we visit exactly the same url. In the real browser, that would not create a history item. But for this problem we are supposed to do. They should better clarify that int the description!

// Two Stacks
// The top of the first stack is the first element in the back history. And the top of the other stack - first element of the forward history. Move urls from one stack to another as you go back and forward.

class BrowserHistory {
public:
    stack<string> h_back, h_forward;
string cur;
BrowserHistory(string homepage) { cur = homepage; }
void visit(string url) {
    h_forward = stack<string>();
    h_back.push(cur);
    cur = url;
}
string back(int steps) {
    while (--steps >= 0 && !h_back.empty()) {
        h_forward.push(cur);
        cur = h_back.top();
        h_back.pop();
    }
    return cur;
}
string forward(int steps) {
    while (--steps >= 0 && !h_forward.empty()) {
        h_back.push(cur);
        cur = h_forward.top();
        h_forward.pop();
    }
    return cur;
}
};
