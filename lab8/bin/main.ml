class store =
  object
    val instance = None
    val mutable name : string option = None
    val mutable address : string option = None
    val mutable books : string list = []

    method get_instance () =
      match instance with
      | Some i -> i
      | None -> new store

    method init ~name:store_name ~address:store_address =
      name <- store_name;
      address <- store_address;
      ()

    method available_books () = books
    method buy_report () = ()
  end
