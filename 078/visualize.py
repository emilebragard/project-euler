import os
os.environ["MPLCONFIGDIR"] = "/tmp/mplconfig"

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import numpy as np
import subprocess

N = 100

P = [[0], [0, 1], [0,1,2], [0,1,2,3], [0,1,3,4,5]]

while len(P) <= N:
    n = len(P)
    row = [0, 1, n//2+1]
    for k in range(3, n):
        row.append(P[n-k][min(k,n-k)] + row[-1])
    row.append(row[-1]+1)
    P.append(row)

# Q[n][k] = ways to split n with piles of at most k, with at least one pile of exactly k
Q = np.zeros((N+1, N+1))
for n in range(1, N+1):
    for k in range(1, n+1):
        Q[n][k] = P[n][k] - P[n][k-1]

data = Q[1:, 1:]  # drop n=0 row and k=0 col

# shift each row left so the diagonal (Q(n,n)=1) lands in the first column,
# and every other value in that row shifts left with it (no wraparound)
shifted = np.zeros_like(data)
for i in range(N):
    shifted[i, :i + 1] = data[i, :i + 1][::-1]
data = shifted

cell_size = 0.4
fig, ax = plt.subplots(figsize=(N * cell_size, N * cell_size))

# color each down-right diagonal (constant n-k) by cycling through 8 high-contrast
# colors, so consecutive diagonals alternate sharply and are easy to trace
rows = np.arange(N)[:, None]
cols = np.arange(N)[None, :]
diag_id = (rows - cols) % 8
diag_masked = np.ma.masked_where(cols > rows, diag_id)

diag_colors = np.array([mcolors.to_rgba(c) for c in [
    "red", "blue", "lime", "magenta", "orange", "cyan", "purple", "yellow",
]])
diag_cmap = mcolors.ListedColormap(diag_colors)
diag_cmap.set_bad(color="white")

im = ax.imshow(diag_masked, cmap=diag_cmap, aspect="auto", origin="upper", vmin=0, vmax=7)

font_size = max(3, int(cell_size * 18))
for n in range(N):
    for k in range(N):
        val = int(data[n][k])
        if val > 0:
            r, g, b, _ = diag_colors[(n - k) % 8]
            luminance = 0.299 * r + 0.587 * g + 0.114 * b
            text_color = "black" if luminance > 0.6 else "white"
            ax.text(k, n, str(val), ha="center", va="center", fontsize=font_size, color=text_color)

ax.set_xlabel("k  (largest pile size allowed, with at least one pile of exactly k)")
ax.set_ylabel("n  (total coins)")
ax.set_title("Q(n,k): partitions of n using piles ≤ k, with at least one pile of k\n(down-right diagonals colored with an 8-color alternating cycle)")
ax.set_xticks(range(N))
ax.set_xticklabels(range(1, N+1))
ax.set_yticks(range(N))
ax.set_yticklabels(range(1, N+1))

plt.tight_layout()

out = os.path.abspath("partition_viz.png")
plt.savefig(out, dpi=150, bbox_inches="tight")
print(f"Saved to {out}")
subprocess.Popen(["explorer.exe", out])
