def is_prime(n):
    """判断是否为素数"""
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    
    # 只需检查到 sqrt(n)
    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i += 2
    return True


print("===== 素数判断器 =====")
print("输入一个整数，程序判断是否为素数")
print("输入 0 或负数退出程序\n")

while True:
    try:
        num = int(input("请输入一个整数: "))
    except ValueError:
        print("⚠️ 输入无效，请输入纯数字！\n")
        continue
    
    if num <= 0:
        print("程序已退出，再见！")
        break
    
    if is_prime(num):
        print(f"✅ {num} 是素数\n")
    else:
        print(f"❌ {num} 不是素数\n")