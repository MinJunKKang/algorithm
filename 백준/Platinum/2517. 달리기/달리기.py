import sys

class FenwickTree:
    def __init__(self, size):
        self.size = size
        self.tree = [0] * (size + 1)

    def sum(self, i):
        ans = 0
        while i <= self.size:
            ans += self.tree[i]
            i += (i & -i)
        return ans

    def update(self, i):
        while i > 0:
            self.tree[i] += 1
            i -= (i & -i)

def main():
    # 입력 받기
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    a = [(int(data[i+1]), i) for i in range(N)]

    # 값 기준으로 정렬
    a.sort()

    # 결과 배열 생성
    result = [0] * N
    for i in range(N):
        result[a[i][1]] = i + 1

    # 펜윅 트리 초기화
    tree = FenwickTree(N)

    # 결과 출력
    output = []
    for i in range(1, N + 1):
        idx = result[i - 1]
        tree.update(idx)
        output.append(str(tree.sum(idx)))

    sys.stdout.write("\n".join(output) + "\n")

if __name__ == "__main__":
    main()
