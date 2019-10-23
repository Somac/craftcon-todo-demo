[@react.component]
let make = (~addTodo) => {
  let (text, setText) =  React.useState(() => "");

  let handleSubmit = e => {
    ReactEvent.Form.preventDefault(e);
    switch text {
    | "" => ()
    | _ => addTodo(text)
    }
    setText(_ => "");
  };

  <form onSubmit={handleSubmit}>
    <input
      type_="text"
      value=text
      onChange={event => setText(ReactEvent.Form.target(event)##value)}
      className="input"
    />
    <button className="button add">{React.string("Add")}</button>
  </form>
}
