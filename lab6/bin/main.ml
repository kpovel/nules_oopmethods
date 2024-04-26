open Lab6

class book ~id ~name ~author ~description:short_description ~price ~category
  ~available =
  object
    val id : int = id
    val mutable name : string = name
    val mutable author : string = author
    val mutable short_description : string = short_description
    val mutable price : int = price
    val mutable category : Category.category = category
    val mutable available : int = available
    method name = name
    method author = author
    method description = short_description
    method price = price
    method category = category
    method available = available
    method update_description description = short_description <- description
    method set_available count = available <- count

    method show =
      Printf.printf
        "Name: %s\n Author: %s\n Description: %s\n Price: %d\n Available: %d"
        name author short_description price available
  end

class customer ~id ~name ~email ~tel =
  object
    val id : int = id
    val mutable name : string = name
    val mutable email : string = email
    val mutable tel : string option = tel
    val mutable order : book list = []
    method add_order_book book = order <- book :: order

    method review_order =
      Printf.printf "%s's order: \n" name;
      List.iter (fun x -> x#show) order

    method make_order =
      Printf.printf "Order was made: \n";
      List.iter (fun x -> x#show) order;
      order <- []
  end

class bibliographer ~id ~name ~tel =
  object
    val id : int = id
    val name : string = name
    val mutable tel : string = tel
    method create_book = new book
    method remove_book = ()
  end

let () =
  let pavlo_customer =
    new customer ~id:1 ~name:"Pavlo" ~email:"thepavlokaras@gmail.com" ~tel:None
  in
  let bib = new bibliographer ~id:2 ~name:"Mike" ~tel:"+380957342069" in
  let real_world_ocaml =
    bib#create_book ~id:1 ~name:"Real World OCaml" ~price:0
      ~author:"YARON MINSKY" ~category:Category.Science ~available:70
      ~description:"FUNCTIONAL PROGRAMMING FOR THE MASSES"
  in

  pavlo_customer#add_order_book real_world_ocaml;
  pavlo_customer#make_order;
  ()
