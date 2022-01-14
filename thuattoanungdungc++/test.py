n = 4

goal_states = []
c = 1
for i in range(n):
    for j in range(n):
        if i == n-1 and j == n-1:
            break
        goal_states.append(set([c]))
        print(1)
        print(goal_states)
        if i > 0 or j > 0:
            goal_states[-1] = goal_states[-1].union(goal_states[-2])
            print(2)
            print(goal_states)
        c += 1
