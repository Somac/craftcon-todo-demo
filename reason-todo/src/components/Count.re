[@react.component]
let make = (~count) => {
  <div className="footer">
    (React.string(string_of_int(count) ++ " items"))
  </div>
}
