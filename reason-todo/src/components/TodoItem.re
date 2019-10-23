let str = React.string;

let lineThroughStyle = () => 
  ReactDOMRe.Style.make(
    ~textDecoration="line-through", ());

[@react.component]
let make = (~item, ~completed, ~toggleTodo, ~removeTodo) => {
  <div className="item">
    <span style={switch completed {
    | true =>lineThroughStyle()
    | false => ReactDOMRe.Style.make()
    }}>
      (str(item))
    </span>
    <span className="end">
      (switch (completed) {
        | false => 
        <button className="button complete" onClick=((_evt) => toggleTodo())>
            {str("Complete")}
        </button>
        | true =>
        <>
          <button className="button remove" onClick=((_evt) => removeTodo())>
            {str("X")}
          </button>
          <button className="button undo" onClick=((_evt) => toggleTodo())>
            <img src="https://img.icons8.com/android/16/000000/undo.png" />
          </button>
        </>
      })
    </span>
  </div>
};
