import java.util.Stack;

class minStack {
    Stack<Long> st;
    long minsf = 0;

    public minStack() {
        st = new Stack<>();
    }

    public void push(int x) {
        long val = x;
        if (st.size() == 0) {
            minsf = val;
            st.push(val);
            return;
        }

        if (val > minsf) {
            st.push(val);
        } else {
            st.push(val - minsf + val);
            minsf = val;
        }
    }

    public int top() {
        if (st.peek() <= minsf) {
            return (int) minsf;
        }
        long val = st.peek();
        return (int) val;
    }

    public void pop() {
        if (st.peek() < minsf) {
            minsf = minsf - st.peek() + minsf;
        }
        st.pop();
    }

    public int getMin() {
        return (int) minsf;
    }
}