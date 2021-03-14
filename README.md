# Data_Structure
## 자료구조 연습 소스입니다.
### 정렬 알고리즘
+ 선택 정렬
  + 가장 작은(큰) 수를 찾아 나가는 방법
  + 초기 배열 상태는 정렬시간에 영향을 주지 않음
  + 오름차순 정렬 순서
    1. 첫 번째부터 마지막까지의 구간에서 가장 작은 수를 구함
    2. 구한 수를 첫 번째 데이터와 교환
    3. 두 번째부터 마지막까지의 구간에서 가장 작은 수를 구함
    4. 구한 수를 두 번째 데이터와 교환
    5. 이 과정을 반복
+ 삽입 정렬
  + 데이터를 한 칸씩 이동시켜 키 값을 적절한 위치에 삽입하는 정렬
  + 데이터가 정렬되어 있을수록 시간은 단축
  + 오름차순 정렬 순서
    1. 키 값보다 좌측의 값이 더 크면 우측으로 한 칸씩 이동
    2. 키 값보다 좌측의 값이 작거나 같으면 바로 우측에 키 값을 삽입
    3. 키 값을 두 번째부터 마지막까지 변경하면서 과정 반복
+ 버블 정렬
  + 인접한 데이터와 비교를 해 교환하면서 정렬하는 방법
  + 초기 데이터가 정렬되어 있을수록 시간은 단축
  + 오름차순 정렬 순서
    1. 인접한 값보다 더 크면 교환하며 끝까지 진행
    2. 범위를 맨 끝부터 하나씩 줄이면서 같은 과정을 반복
    3. 더 이상 자료의 교환이 없으면 종료
+ 쉘 정렬
  + 이동하는 빈도수가 많은 삽입정렬을 개선한 알고리즘
  + 일정한 간격의 데이터끼리 삽입정렬하여 데이터 이동횟수를 줄임
  + 오름차순 정렬 순서
    1. 일정한 간격 t끼리 묶어 삽입정렬을 수행(t=n/2)
    2. 간격을 줄여나가면서 삽입정렬을 반복(t=t/2)
    3. 간격이 1이 될 때까지 반복수행
+ 퀵 정렬
  + 기준 값보다 작으면 왼쪽, 크면 오른쪽에 배치하는 방법으로 정렬
  + 데이터가 정렬되어 있을수록 시간은 오히려 많이 소요됨
  + 오름차순 정렬 순서
    1. 맨 처음 데이터를 key로 함
    2. 좌측에서 우측으로 가면서 key보다 큰 값을 찾음. 우측에서는 좌측으로 가면서 작은 값을 찾음. 큰 값이 작은 값보다 좌측에 있으면 교환. 우측에 있으면 key와 작은 값을 교환. key를 기준으로 좌측에는 작은 값, 우측에는 큰 값이 배치
    3. 나누어진 부분의 데이터가 2개 이상이면 재귀호출로 전 과정을 반복
+ 힙 정렬
  + 최대 힙 또는 최소 힙을 구성하여 정렬해나가는 방법
  + 최대 힙은 모든 노드에 대하여 부모 노드는 자식 노드보다 크거나 같은 값을 가지고, 최소 힙은 모든 노드에 대하여 부모 노드는 자식 노드보다 작거나 같은 값을 가짐
  + 오름차순 정렬 순서
    1. 최대 힙을 구성함
    2. root 값과 마지막 노드 값 교환하고 범위를 1 감소
    3. 최대 힙 다시 구성
    4. 과정 b, c를 범위 1일 될 때까지 반복
+ 병합 정렬
  + 데이터를 병합하면서 정렬하는 방법
  + 초기 데이터가 정렬되어 있을수록 약간의 시간은 단축되나 크게 영향은 없음
  + 2-Way Merge Sort 순서, 오름차순
    1. 데이터를 하나가 될 때까지 분할
    2. 하나로 분할된 데이터를 오름차순으로 병합
    3. 정렬된 두 그룹을 병합
    4. 한 그룹으로 병합될 때까지 위의 과정을 반복
+ 기수 정렬
  + 숫자를 0~9까지 10개의 버킷에 분배, 회수를 반복하면서 정렬하는 방법
  + 초기 데이터는 정렬 시간과 무관함
  + 오름차순 정렬 순서
    1. 정렬대상 중 가장 큰 수를 구함
    2. 전체 데이터를 1자리 값에 따라 0~9까지의 해당 버킷에 넣음
    3. 0 버킷부터 넣은 순서대로 회수
    4. 위의 과정을 10자리, 100자리, ... , 가장 놓은 자리까지 반복
