fn main()
{
    let x: u32 = 2_000_000_000;
    let y: u32 = 3_000_000_000;

    if let Some(result) = x.checked_add(y)
    {
        println!("Checked addition: {}", result);
    }
    else
    {
        println!("Overflow occured!");
    }

    let a: u32 = 0;
    let b: u32 = 1;
    let result = a.wrapping_sub(b);
    println!("Wrapping Subtraction: {}", result);

}