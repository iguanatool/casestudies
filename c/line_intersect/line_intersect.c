int line_intersect(int ax1, int ay1, int ax2, int ay2,
                   int bx1, int by1, int bx2, int by2) {

    double ua_t = (bx2 - bx1) * (ay1 - by1) - (by2 - by1) * (ax1 - bx1);
    double ub_t = (ax2 - ax1) * (ay1 - by1) - (ay2 - ay1) * (ax1 - bx1);
    double u_b = (by2 - by1) * (ax2 - ax1) - (bx2 - bx1) * (ay2 - ay1);

    if (u_b != 0) {
        double ua = ua_t / u_b;
        double ub = ub_t / u_b;

        if (0 <= ua && ua <= 1 && 0 <= ub && ub <= 1) {
            return 1;
        }
        return 0;

    } else {
        if (ua_t == 0 || ub_t == 0) {
            return 1;
        }

        return 0;
    }
}
