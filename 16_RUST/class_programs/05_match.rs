fn main()
{
    let age = 100;

    match age
    {
        100 => println!("too old"),
        50 => println!("old"),
        30 => println!("yound"),
        _ => println!("baby"),
    }
}
