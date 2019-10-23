let str = React.string;

[@react.component]
let make = (~count) => {
  <div className="footer">
    (str(string_of_int(count) ++ " items"))
  </div>
}
