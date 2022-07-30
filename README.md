# sm3-optimization
   对于长度为l（l<2^64）比特的消息m，sm3杂凑算法经过填充、迭代压缩生成杂凑值，杂凑值输出为256bit。实现原理见 https://www.doc88.com/p-9347835163554.html?s=rel&id=9

   优化：
1、 在sm3算法中出现多个循环，我通过尝试对部分循环进行循环展开，提高并行度从而达到优化的目的。

2、也可以使用simd指令对sm3算法进行优化。
    
   优化前：
   
   <img width="416" alt="image" src="https://user-images.githubusercontent.com/110089380/181920435-0fb5dd8a-e1b6-4ada-b266-521b00f99a42.png">
   
   通过方式1优化后：
   
   <img width="415" alt="image" src="https://user-images.githubusercontent.com/110089380/181920457-4d9c655b-3c6e-4e40-ac74-43e807fa2bba.png">
   
   对于方式2，由于在实现sm3算法的过程中都是对字符串进行操作，我不清楚如何使用simd指令处理字符和字符串，于是并没有实现。
