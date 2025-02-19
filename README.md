> 受 [Nkugwa Mark William](https://nkugwamarkwilliam.medium.com/hash-table-implementation-in-c-75545fd4b3e6) 的启发，跟随他的思路用 `C 语言` 实现一个哈希并作了一些修改。

## 介绍

这是一个基于 C 语言的哈希表实现项目，使用链地址法解决哈希冲突。哈希表支持插入、查找、删除和打印功能，适用于存储键值对数据。

## 功能特性

1. 插入键值对：将键值对插入哈希表。

2. 查找键值对：根据键查找对应的值。

3. 删除键值对：根据键删除对应的键值对。

4. 打印哈希表：打印哈希表中所有键值对的内容。

5. 链地址法解决冲突：使用链表处理哈希冲突。

## 项目结构

```bash
C-Hash/
├── hash_table.h       # 哈希表头文件，包含结构定义和函数声明
├── hash_table.c       # 哈希表实现文件，包含函数定义
├── main.c             # 示例程序，演示哈希表的使用
└── README.md          # 项目说明文档
```

## 快速开始

1. 克隆或下载项目代码。

2. 打开终端，进入项目目录。

3. 使用以下命令编译代码生成可执行文件：

```bash
gcc -o hash main.c hash_table.c
```

运行生成的可执行文件：

```bash
./hash_table_program
```

## 技术文档

### 数据结构

```c
typedef struct node {
    char *key;
    int value;
    struct node *next;
} node;
```

### 函数说明

```c
// 插入键值对到哈希表中。
void hash_table_insert(node **table, const char *key, int value)

// 根据键查找对应的值。如果找到，返回对应的值；否则返回 -1。
int hash_table_search(node **table, const char *key)

// 根据键删除对应的键值对。
void hash_table_remove(node **table, const char *key)

// 打印哈希表中所有键值对的内容。
void print_hash_table(node **table)
```

### 注意

- 内存管理：项目中使用了 malloc 和 strdup 动态分配内存，请确保在不需要哈希表时释放所有节点的内存，避免内存泄漏。

- 哈希函数：当前哈希函数较为简单，适用于学习和演示。在实际应用中，建议使用更复杂的哈希函数以减少冲突。

- 键的唯一性：哈希表假设键是唯一的。如果插入重复的键，后插入的值会**覆盖**先前的值。

- 性能：哈希表的性能取决于哈希函数的设计和冲突处理方式。在极端情况下（如所有键都哈希到同一个索引），性能会退化为链表。

- 隐藏了内部实现细节（如 hash 和 create_node 函数被标记为 static，仅在当前 .c 文件可见）

- 通过头文件保护宏 #ifndef 防止重复包含

### TODO

- [ ] 动态调整哈希表大小,以适应不同数据
- [ ] 支持更多数据类型
