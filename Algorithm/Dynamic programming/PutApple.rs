
fn putApple(m: i32,n: i32) -> i32 {
    if m==0||n==1{
        1
    }
    else if n>m{
        putApple(m,m)
    }
    else{
        putApple(m,n-1)+putApple(m-n,n)
    }
}
